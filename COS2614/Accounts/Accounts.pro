#-------------------------------------------------
#
# Project created by QtCreator 2022-07-27T15:48:32
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Accounts
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    customer.cpp \
    transaction.cpp \
    account.cpp \
    savings.cpp \
    cheque.cpp \
    accountlist.cpp

HEADERS += \
    customer.h \
    transaction.h \
    account.h \
    savings.h \
    cheque.h \
    accountlist.h
