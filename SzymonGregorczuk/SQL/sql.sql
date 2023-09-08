IF NOT EXISTS (
        SELECT *
        FROM sys.databases
        WHERE name = 'gym'
        )
BEGIN
    CREATE DATABASE gym
END
GO

USE gym
GO
IF OBJECT_ID(N'dbo.wyposazenie', N'U') IS NULL
CREATE TABLE wyposazenie(
	id int NOT NULL PRIMARY KEY,
	rodzaj_wyposa¿enia varchar,
	ilosc_wyposazenia int
);
IF OBJECT_ID(N'dbo.pracownik', N'U') IS NULL
CREATE TABLE pracownik(
	id int NOT NULL PRIMARY KEY,
	PESEL int,
	imie varchar,
	nazwisko varchar,
	nr_telefonu int,
	mail varchar,
	pensja float,
	godziny_pracy varchar,
	posada varchar
	);
IF OBJECT_ID(N'dbo.karta', N'U') IS NULL
CREATE TABLE karta(
	id int NOT NULL PRIMARY KEY,
	waznosc datetime2,
	data_godzina_wejscia datetime2,
	data_godzina_wyjscia datetime2
);
IF OBJECT_ID(N'dbo.lokalizacja', N'U') IS NULL
CREATE TABLE lokalizacja(
	id int NOT NULL PRIMARY KEY,
	adres varchar,
	karta_id int FOREIGN KEY REFERENCES karta(id),
	pracownik_id int FOREIGN KEY REFERENCES pracownik(id),
	wyposa¿enie_id int FOREIGN KEY REFERENCES wyposazenie(id)
	);

IF OBJECT_ID(N'dbo.klient', N'U') IS NULL
CREATE TABLE klient(
	id int NOT NULL PRIMARY KEY,
	imie varchar,
	naziwsko varchar,
	karta_id int FOREIGN KEY REFERENCES karta (id)
);
IF OBJECT_ID(N'dbo.pracownik_lokalizacja', N'U') IS NULL
CREATE TABLE pracownik_lokalizacja(
	id_pracownik int FOREIGN KEY REFERENCES pracownik (id),
	id_lokalizacja int FOREIGN KEY REFERENCES lokalizacja (id)
);

