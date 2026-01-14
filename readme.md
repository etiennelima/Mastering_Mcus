# STM32 Mastering MCUs — Peripheral Drivers with HAL

Este repositório contém estudos e implementações desenvolvidos durante o curso **Mastering Microcontroller Units (MCUs)**, com foco em um **nível intermediário de abstração** entre HAL de alto nível e programação bare metal.

O objetivo principal é **desenvolver drivers de periféricos reutilizáveis**, utilizando a HAL apenas como camada de inicialização e suporte básico.

---

## 📌 Objetivo do Projeto

Este projeto busca:

- Entender a HAL além do uso “pronto” gerado pelo CubeMX
- Criar **drivers próprios de periféricos**
- Trabalhar com **abstração, modularização e reutilização**
- Servir como ponte entre:
  - programação HAL de alto nível
  - programação bare metal em nível de registradores

---

## 🧠 Filosofia de Desenvolvimento

O fluxo adotado neste projeto é:

1. **STM32CubeMX**
   - Usado apenas para:
     - configuração de clock
     - pinout
     - inicialização básica da HAL

2. **HAL**
   - Utilizada como camada de suporte
   - Não usada diretamente na aplicação final

3. **Drivers de Periféricos**
   - Desenvolvidos manualmente
   - Encapsulam lógica de UART, GPIO, SPI, I2C, etc.
   - Interface limpa para a aplicação

Este modelo aproxima o desenvolvimento profissional de firmware utilizado na indústria.

---

## 📁 Estrutura do Repositório

A estrutura segue uma organização por módulos e periféricos:


