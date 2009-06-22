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
CONFIG -= gui
CONFIG += thread
CONFIG += console


# Indica se deve criar um makefile com suporte aos simbolos de debug ou nao
CONFIG += debug
#CONFIG += release

# Habilitando os warnings do compilador no makefile.
CONFIG += warn_on

#release {
#	DEFINES += QT_NO_DEBUG_OUTPUT
#	DEFINES += QT_NO_WARNING_OUTPUT
#}

# Versao do lojaSim =]
VERSION = 1.0.0

# Nome do executavel criado
TARGET = lojaSim_$${VERSION}

## ADICIONEM OS ARQUIVOS AQUI ##
# Arquivos .h
HEADERS += src/lojaSim.h
HEADERS += src/cliente.h
HEADERS += src/clientsNames.h
HEADERS += src/globaldef.h
HEADERS += src/vendedorNames.h
HEADERS += src/vendedor.h
HEADERS += src/estoquista.h
HEADERS += src/caixa.h
HEADERS += src/vendaDispatcher.h
HEADERS += src/pedidoDispatcher.h
HEADERS += src/pagamentoDispatcher.h
HEADERS += src/pedido.h
HEADERS += src/logSys.h
HEADERS += src/vendaThread.h
HEADERS += src/pagamentoThread.h
HEADERS += src/pedidoThread.h
HEADERS += src/logMessageCompra.h
HEADERS += src/logMessageVenda.h
HEADERS += src/geradorCliente.h

# Arquivos .cpp
SOURCES += src/lojaSim.cpp
SOURCES += src/cliente.cpp
SOURCES += src/vendedor.cpp
SOURCES += src/estoquista.cpp
SOURCES += src/caixa.cpp
SOURCES += src/vendaDispatcher.cpp
SOURCES += src/pedidoDispatcher.cpp
SOURCES += src/pagamentoDispatcher.cpp
SOURCES += src/pedido.cpp
SOURCES += src/logSys.cpp
SOURCES += src/vendaThread.cpp
SOURCES += src/pagamentoThread.cpp
SOURCES += src/pedidoThread.cpp
SOURCES += src/logMessageCompra.cpp
SOURCES += src/logMessageVenda.cpp
SOURCES += src/geradorCliente.cpp

# Arquivos .ui (QTDesigner)
#FORMS += src/meuform.ui

# Arquivos dos resources (imagens por exemplo) do programa
# RESOURCES += lojaSim.qrc
