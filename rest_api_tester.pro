TEMPLATE = subdirs

SUBDIRS += \
    api \
    gui \
    tests

gui.depends = api
tests.depends = api
