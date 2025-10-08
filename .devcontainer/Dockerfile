# Imagem base: Ubuntu 22.04
FROM ubuntu:22.04

# Evita prompts interativos durante a instalação de pacotes
ENV DEBIAN_FRONTEND=noninteractive

# Atualiza os pacotes e instala as ferramentas essenciais para desenvolvimento em C
# build-essential: Inclui compiladores como gcc, g++ e o make.
# gdb: O depurador GNU, fundamental para depurar código C.
# valgrind: Ferramenta para detecção de memory leaks e profiling.
# cmake: Sistema de automação de compilação multi-plataforma.
# git, curl, vim, sudo: Utilitários gerais de desenvolvimento.
RUN apt-get update && apt-get install -y \
    build-essential \
    gdb \
    valgrind \
    cmake \
    git \
    curl \
    vim \
    sudo \
    && rm -rf /var/lib/apt/lists/*

# Cria um usuário não-root 'vscode' e o adiciona ao grupo sudo para permissões
RUN useradd -m -s /bin/bash -G sudo vscode
# Configura o sudo para não pedir senha para o usuário 'vscode'
RUN echo "vscode ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# Muda para o usuário 'vscode'
USER vscode

# Define o diretório de trabalho padrão dentro do home do usuário
WORKDIR /home/vscode/workspace

# Mantém o container rodando para que possa ser usado como um ambiente de desenvolvimento
CMD [ "sleep", "infinity" ]
