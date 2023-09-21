IF NOT EXISTS (
        SELECT *
        FROM sys.databases
        WHERE name = 'biblioteka'
        )
BEGIN
    CREATE DATABASE biblioteka
END
GO

USE biblioteka
GO
IF OBJECT_ID(N'dbo.klient', N'U') IS NULL
CREATE TABLE klient(
	id_kli int NOT NULL PRIMARY KEY,
	imie varchar,
	nazwisko varchar,
);
IF OBJECT_ID(N'dbo.pracownicy', N'U') IS NULL
CREATE TABLE pracownicy(
	id_pra int NOT NULL PRIMARY KEY,
	imie varchar,
	nazwisko varchar,
	pensja float,
	godziny_pracy varchar,
	rola_pracownika varchar
	);
IF OBJECT_ID(N'dbo.ksiazki', N'U') IS NULL
CREATE TABLE ksiazki(
	id_ks int NOT NULL PRIMARY KEY,
	nazwa varchar,
	autor varchar,
	wydawnictwo varchar
	
);
IF OBJECT_ID(N'dbo.lokalizacja', N'U') IS NULL
CREATE TABLE lokalizacja(
	id int NOT NULL PRIMARY KEY,
	miejscowosc varchar,
	ulica varchar,
	wojewodztwo varchar,
	pracownik_id int FOREIGN KEY REFERENCES pracownicy(id_pra)
	);

IF OBJECT_ID(N'dbo.wypozyczenia', N'U') IS NULL
CREATE TABLE wypozyczenia(
	id_wyp int NOT NULL PRIMARY KEY,
	data_wypozyczenia date,
	ilosc int,
	id_ksiazki int FOREIGN KEY REFERENCES ksiazki(id_ks)
);


