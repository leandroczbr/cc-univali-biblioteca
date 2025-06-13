# Sistema de Acesso à Biblioteca 📚

Este projeto é um sistema de controle de acesso para uma biblioteca universitária, desenvolvido em C. Ele permite verificar se um usuário pode ou não acessar a biblioteca com base em sua categoria, horário e dia da semana.

## 🚀 Funcionalidades

- Coleta de dados como matrícula, idade, curso e categoria do usuário.
- Conversão do dia da semana para valor numérico.
- Validação de faixa de idade e horário.
- Verificação de débitos com a biblioteca.
- Autorização ou recusa de acesso com base em regras específicas.

## ✅ Regras de Acesso

| Categoria           | Débito | Dias Permitidos         | Horário Permitido |
|---------------------|--------|--------------------------|-------------------|
| Professor           | Qualquer | Qualquer dia             | Qualquer hora     |
| Aluno de Graduação  | Não     | Segunda a Sexta          | 08h às 22h        |
| Aluno de Pós-graduação | Não | Segunda a Sábado         | 08h às 22h        |
| Visitante           | Não     | Segunda a Sexta          | 09h às 17h        |

## 📦 Como Executar

1. Compile o código com um compilador C, por exemplo:
```
gcc biblioteca.c -o biblioteca
```
2. Execute o programa:
```
./biblioteca
```
