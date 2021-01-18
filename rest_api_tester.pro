TEMPLATE = subdirs

SUBDIRS += \
    api \
    cli \
    gui \
    tests

gui.depends = api
tests.depends = api
cli.depends = api
