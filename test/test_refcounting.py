from gc import collect

from pyalpm import Handle
from conftest import TEST_MIRROR, REPO_1, ARCH


def get_localdb():
    handle = Handle('/', '/tmp/')
    return handle.get_localdb()


def register_syncdb():
    handle = Handle('/', '/tmp/')
    repo = handle.register_syncdb(REPO_1, 0)
    repo.servers = [TEST_MIRROR.format(REPO_1, ARCH)]
    return repo


def get_syncdb():
    # Return syncdb, so handle should go out of scope
    handle = Handle('/', '/tmp/')
    repo = handle.register_syncdb(REPO_1, 0)
    repo.servers = [TEST_MIRROR.format(REPO_1, ARCH)]
    return handle.get_syncdbs()[0]


def get_pkg_search():
    db = get_syncdb()
    db.update(False)
    return db.search('pacman')[0]


def test_localdb_segfault():
    localdb = get_localdb()
    collect()
    x = localdb.search('yay')
    assert x == []


def test_syncdb_segfault():
    syncdb = get_syncdb()
    collect()
    assert syncdb.search('yay') == []


def test_register_syncdb_segfault():
    syncdb = register_syncdb()
    collect()
    assert syncdb.search('yay') == []
