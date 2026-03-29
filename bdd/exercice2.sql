--criação do banco de dados
CREATE DATABASE TPAula4
Go
--torna o banco de dados ativo
USE TPAula4
Go
--criação da tabela Produto
CREATE TABLE Produto (
    IdProduto INT IDENTITY(1,1) PRIMARY KEY,
    NomeProduto VARCHAR(100) NOT NULL,
    Categoria VARCHAR(50) NOT NULL,
    Marca VARCHAR(50) NOT NULL,
    Preco DECIMAL(10,2) NOT NULL,
    Estoque INT NOT NULL,
    Desconto DECIMAL(5,2) NULL,
    Ativo CHAR(1) NOT NULL,
    DataCadastro DATE NOT NULL
)
go
--inserção dos registros
INSERT INTO Produto (NomeProduto, Categoria, Marca, Preco, Estoque, Desconto, Ativo, DataCadastro)
VALUES
('Notebook Ultra 14',      'Informatica',  'Dell',      3500.00, 12, 10.00, 'S', '2024-01-10'),
('Notebook Vision 15',     'Informatica',  'Lenovo',    4200.00,  8, 12.50, 'S', '2024-02-05'),
('Mouse Optico USB',       'Perifericos',  'Logitech',    80.00, 50,  5.00, 'S', '2024-01-15'),
('Teclado Mecanico RGB',   'Perifericos',  'Redragon',   250.00, 20, 15.00, 'S', '2024-03-01'),
('Monitor LED 24',         'Monitores',    'Samsung',    900.00, 15,  8.00, 'S', '2024-02-20'),
('Monitor Gamer 27',       'Monitores',    'LG',        1650.00,  6, 10.00, 'S', '2024-03-10'),
('Impressora EcoTank',     'Impressoras',  'Epson',     1200.00,  5,  7.50, 'S', '2024-01-22'),
('HD Externo 1TB',         'Armazenamento','Seagate',    450.00, 18,  0.00, 'S', '2024-02-12'),
('SSD 500GB',              'Armazenamento','Kingston',   320.00, 25, 10.00, 'S', '2024-01-30'),
('Pen Drive 64GB',         'Armazenamento','Sandisk',     55.00, 60,  0.00, 'S', '2024-02-18'),
('Cadeira Gamer Pro',      'Moveis',       'DXRacer',   1800.00,  4, 20.00, 'S', '2024-03-15'),
('Mesa Escritorio 120cm',  'Moveis',       'Kappesberg', 650.00, 10,  5.00, 'S', '2024-01-08'),
('Webcam Full HD',         'Perifericos',  'Logitech',   300.00, 14,  0.00, 'S', '2024-02-28'),
('Headset Gamer X',        'Audio',        'HyperX',     480.00, 16, 12.00, 'S', '2024-03-05'),
('Caixa de Som Bluetooth', 'Audio',        'JBL',        350.00, 22,  6.00, 'S', '2024-01-25'),
('Smartphone Alpha',       'Celulares',    'Samsung',   2200.00,  9, 10.00, 'S', '2024-02-08'),
('Smartphone Max',         'Celulares',    'Motorola',  1800.00, 11,  8.50, 'S', '2024-03-12'),
('Carregador Turbo',       'Acessorios',   'Baseus',     120.00, 35,  0.00, 'S', '2024-01-18'),
('Cabo USB-C 1m',          'Acessorios',   'Anker',       40.00, 70,  0.00, 'S', '2024-02-02'),
('Tablet Plus 10',         'Tablets',      'Samsung',   1600.00,  7,  9.00, 'N', '2024-03-20');

select* from Produto;

---1)
SELECT ABS(-250);
---2)
SELECT NomeProduto, CEILING(Preco) AS PrecoArredondado FROM Produto;
---3)
SELECT NomeProduto,CAST(ROUND(Preco, 1)AS DECIMAL(6,2)) AS PrecoArredondado  FROM Produto;
---4)
SELECT NomeProduto, CEILING(Preco) AS PrecoArredondadoCima FROM Produto;
---5)
SELECT NomeProduto, FLOOR(Preco) AS PrecoArredondadoBaixo FROM Produto;
---6)
SELECT NomeProduto, POWER(Preco, 2) AS PrecoAoQuadrado FROM Produto;
---7)
SELECT NomeProduto, POWER(Preco, 3) AS PrecoAoCubo FROM Produto;
---8)
SELECT NomeProduto, SQRT(Estoque) AS RaizQuadradaEstoque FROM Produto;
---9)
SELECT NomeProduto, Preco * 1.15 AS PrecoComAumento FROM Produto;
---10)
SELECT NomeProduto FROM Produto WHERE POWER(Preco, 2) > 1000000;
 

 ---Parte 2 - Funções de String (11-25)

 
---11)
SELECT ASCII('A') AS CodigoASCII;
---12)
SELECT CHAR(66) AS Caractere;
---13)
SELECT UPPER(NomeProduto) AS NomeMaiusculo FROM Produto;
---14)
SELECT LOWER(NomeProduto) AS NomeMinusculo FROM Produto;
---15)
SELECT NomeProduto, LEN(NomeProduto) AS TamanhoNome FROM Produto;
---16)
SELECT NomeProduto, LEFT(NomeProduto, 5) AS Primeiros5 FROM Produto;
---17)
SELECT NomeProduto, RIGHT(NomeProduto, 4) AS Ultimos4 FROM Produto;
---18)
SELECT NomeProduto, CHARINDEX('Gamer', NomeProduto) AS PosicaoGamer FROM Produto;
---19)
SELECT NomeProduto, REPLACE(NomeProduto, ' ', '_') AS NomeComUnderline FROM Produto;
---20)
SELECT NomeProduto, REVERSE(NomeProduto) AS NomeInvertido FROM Produto;
---21)
SELECT NomeProduto + '     ' + Marca AS NomeMarca FROM Produto;
---22)
SELECT REPLICATE('*', 10) AS Asteriscos;
---23)
SELECT NomeProduto, STR(Preco, 10, 2) AS PrecoTexto FROM Produto;
---24)
SELECT value AS Produto FROM STRING_SPLIT('Notebook,Mouse,Teclado', ',');
---25)
SELECT NomeProduto, LEFT(Marca, 3) AS InicioMarca FROM Produto;
 

 --- Parte 3 - Funcoes de String Avancadas 

 
---26)
SELECT NomeProduto, CHARINDEX('Pro', NomeProduto) AS PosicaoPro FROM Produto;
---27)
SELECT NomeProduto, QUOTENAME(NomeProduto) AS NomeEntreColchetes FROM Produto;
---28)
SELECT STUFF('ABCDE', 2, 2, 'XX') AS StringModificada;
---29)
SELECT CONCAT_WS(' - ', NomeProduto, Marca, Categoria) AS Descricao FROM Produto;
---30)
SELECT DIFFERENCE('Mouse', 'Mause') AS Similaridade;
 

 --- Parte 4 - Funcoes de Data 

 
---31)
SELECT GETDATE() AS DataAtual;
---32)
SELECT DAY(GETDATE()) AS Dia, MONTH(GETDATE()) AS Mes, YEAR(GETDATE()) AS Ano;
---33)
SELECT
    NomeProduto,
    DAY(DataCadastro)   AS DiaCadastro,
    MONTH(DataCadastro) AS MesCadastro,
    YEAR(DataCadastro)  AS AnoCadastro
FROM Produto;
---34)
SELECT DATEADD(DAY, 10, GETDATE()) AS DataMais10Dias;
---35)
SELECT NomeProduto, DATEADD(DAY, 30, DataCadastro) AS DataCadastroMais30 FROM Produto;
---36)
SELECT NomeProduto, DATEDIFF(DAY, DataCadastro, GETDATE()) AS DiasDesideCadastro FROM Produto;
---37)
SELECT DATENAME(MONTH, GETDATE()) AS NomeMesAtual;
---38)
SELECT MONTH(GETDATE()) AS NumeroMesAtual;
---39)
SELECT ISDATE('2024-02-30') AS DataValida;
---40)
SELECT NomeProduto, DataCadastro FROM Produto
WHERE DataCadastro >= DATEADD(DAY, -30, GETDATE());
 

--- Desafios 

 
---41)
SELECT CONCAT_WS(' - ', NomeProduto, Marca, CAST(YEAR(DataCadastro) AS VARCHAR)) AS Descricao
FROM Produto;
---42)
SELECT UPPER(NomeProduto) AS NomeMaiusculo, ROUND(Preco, 0) AS PrecoArredondado
FROM Produto;
---43)
SELECT NomeProduto, DATENAME(MONTH, DataCadastro) AS MesPorExtenso
FROM Produto;
---44)
SELECT NomeProduto, DataCadastro FROM Produto
WHERE DATEDIFF(DAY, DataCadastro, GETDATE()) > 60;
---45)
SELECT
    NomeProduto,
    Marca,
    Categoria,
    Preco,
    Estoque,
    DataCadastro,
    ROUND(Preco * 1.10, 2) AS PrecoComAumento
FROM Produto;
 

--- Questoes Estilo Concurso 

 
---46) Resposta: b) preco com 2 casas decimais
SELECT ROUND(Preco, 2) FROM Produto;
 
---47) Resposta: b) nome em maiusculo
SELECT UPPER(NomeProduto) FROM Produto;
 
---48) Resposta: b) retorna a diferenca em dias
SELECT DATEDIFF(DAY, DataCadastro, GETDATE()) FROM Produto;
 
---49) Resposta: b) primeiros 5 caracteres
SELECT LEFT(NomeProduto, 5) FROM Produto;
 
---50) Resposta: b) substitui espacos por underline
SELECT REPLACE(NomeProduto, ' ', '_') FROM Produto;