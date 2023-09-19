use master
GO

IF NOT EXISTS (
        SELECT *
        FROM sys.databases
        WHERE name = 'sus'
        )
BEGIN
    CREATE DATABASE sus
END
GO

USE sus
GO
if OBJECT_ID('N dbo.zoo',N' U') is null
create table zoo (
	id_zoo int not null  primary key,
	miasto varchar
	
);
if OBJECT_ID('N dbo.budynki',N' U') is null
create table budynki(
	id_budynku int not null primary key,
	id_zwierza int,
	id_zoo int foreign key references zoo(id_zoo),
	cena_wejscie float,
	nazwa varchar
);

if OBJECT_ID('N dbo.pracownicy',N' U') is null
create table pracownicy(
	id_pracownika int not null primary key  ,
	imie varchar,
	nazwisko varchar,
	stanowisko varchar
);

if OBJECT_ID('N dbo.opiekuny',N' U') is null
create table opiekuny (
	id_opiekuna int not null primary key ,
	id_pracownika int foreign key references pracownicy(id_pracownika),
	
);

if OBJECT_ID('N dbo.zwierzenta',N' U') is null
create table zwierzenta (
	id_zwierza int not null primary key ,
	id_opiekuna int foreign key references opiekuny(id_opiekuna),
	id_budynku int  foreign key references budynki(id_budynku),
	gatunek varchar,
	bezpieczne_dla_dzieci int
);

