---Exercício 1---
/*CREATE DATABASE Empresa;
GO

USE Empresa;
GO

CREATE TABLE Funcionario (
	Id INT PRIMARY KEY IDENTITY(1,1),
	Nome VARCHAR(100) NOT NULL,
	Salario DECIMAL(10,2),
	DataAdmmissao DATE NOT NULL,
	Email VARCHAR(150),
);*/


---Exercício 2---
/*CREATE DATABASE EscolaDB;
GO

USE EscolaDB;
GO

CREATE TABLE Curso (
	IdCurso INT PRIMARY KEY IDENTITY (1,1),
	NomeCurso VARCHAR(100) NOT NULL,
	CargaHoraria INT NOT NULL,
	);

CREATE TABLE Professor (
	IdProfessor INT PRIMARY KEY IDENTITY (1,1),
	NomeProfessor VARCHAR(100) NOT NULL,
	Especialidade VARCHAR(100),
	DataContratacao DATE NOT NULL,
);

SELECT* FROM Curso;
select* from Professor; */

---Exercício 3---

CREATE DATABASE Loja;
GO

USE Loja;
GO

CREATE TABLE Produto (
IdProduto INT PRIMARY KEY IDENTITY(1,1),
NomeProduto VARCHAR(150) NOT NULL,
Preco DECIMAL(8,2) NOT NULL,
Estoque INT NOT NULL,
DataCadastro DATETIME NOT NULL
);

select* from Produto;