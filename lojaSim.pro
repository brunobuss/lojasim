######################################################################
# lojaSim qmake
######################################################################

# app indica ao qmake que estamos montando uma aplicacão
TEMPLATE = app

# Diretórios onde estarão outros arquivos do projeto
DEPENDPATH += src
INCLUDEPATH += .
INCLUDEPATH += src

# Pasta onde os arquivos temporarios de compilacao ficaram armazenados
OBJECTS_DIR = tmp
MOC_DIR = tmp
RCC_DIR = tmp

# Diretorio onde os arquivos executaveis serao gerados
DESTDIR = bin

# Indica ao qmake que vamos utilizar a biblioteca qt
# com os modulos core e gui (que sao os que utilizaremos)
CONFIG += qt
CONFIG += thread

# Indica se deve criar um makefile com suporte aos simbolos de debug ou nao
CONFIG += debug
#CONFIG += release

# Habilitando os warnings do compilador no makefile.
CONFIG += warn_on

# Se estivermos em uma plataforma Windows
win32 {
    # Se estiver em modo debug, incluimos as bibliotecas de console para podermos
    # utilizar funcoes de debug como a qDebug():
    # http://doc.qtsoftware.com/4.5/qtglobal.html#qDebug
    debug {
    CONFIG += console
    }

    # Então configura de acordo.
    CONFIG += windows
}

# Se estivermos em ambiente unix
unix {
    CONFIG += x11
}


# Versao do lojaSim =]
VERSION = 0.0.1

# Nome do executavel criado
TARGET = lojaSim_$${VERSION}

## ADICIONEM OS ARQUIVOS AQUI ##
# Arquivos .h
#HEADERS += src/bla.h
HEADERS += src/cliente.h
HEADERS += src/clientsNames.h
HEADERS += src/globaldef.h
HEADERS += src/sellerNames.h
HEADERS += src/seller.h

# Arquivos .cpp
#SOURCES += src/bla.cpp
SOURCES += src/cliente.cpp
SOURCES += src/seller.cpp

# Arquivos .ui (QTDesigner)
#FORMS += src/meuform.ui

# Arquivos dos resources (imagens por exemplo) do programa
# RESOURCES += lojaSim.qrc
