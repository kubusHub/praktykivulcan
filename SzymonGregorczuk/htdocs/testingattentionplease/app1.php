<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" type="text/css" href="style.css?v=2">
</head>
<body>
<?php
    $serverName = "PSIR-00682018";
    $database = "gym";
    $uid = "";
    $pass = "";

    $connection = [
        "Database" => $database,
        "Uid" => $uid,
        "PWD" => $pass
    ];

    $conn = sqlsrv_connect($serverName, $connection);

    if (!$conn) {
        die(print_r(sqlsrv_errors(), true));
    }

    $sql = "SELECT COLUMN_NAME
            FROM INFORMATION_SCHEMA.COLUMNS
            WHERE TABLE_NAME = 'pracownik'";
    $stmt = sqlsrv_query($conn, $sql);

    if ($stmt === false) {
        die(print_r(sqlsrv_errors(), true));
    }
    $columns = [];
    while ($row = sqlsrv_fetch_array($stmt, SQLSRV_FETCH_ASSOC)) {
        $columns[] = $row['COLUMN_NAME'];
    }

    ?>
	<center>
		<h1>Storing Form data in Database</h1>
		<form action="connection.php" target="app.php" method="post">
            <?php
            foreach($columns as $colname){
                if($colname != 'id'){
                echo "<p>";
                echo "<label for='$colname'>$colname</label>";
                echo "<input type='text' placeholder='Enter Data' value='abcabc' name='$colname'>";
                echo "</p>";
                echo "</br>";
            };
            
            }
            ?>
             <!-- <p>
                <label for="pesel">PESEL</label>
                <input type="number" value=0822041 name="pesel" id="pesel">
			</p>
            <p>
                <label for="imie">Imie</label>
                <input type="text" value="szymon" name="imie" id="imie">
			</p>
            <p>
                <label for="nazwisko">Nazwisko</label>
                <input type="text" name="nazwisko" value="andrzejczyk" id="nazwisko">
			</p>			
            <p>
                <label for="email">Email</label>
                <input type="text" name="email" value="zaosheng@gmail.com" id="email">
			</p>
            <p>
                <label for="nrtelefonu">Numer telefonu</label>
                <input type="number" name="nrtelefonu" value=670666887 id="nrtelefonu">
            </p>
            <p>
                <label for="pensja">pensja</label>
                <input type="number" name="pensja" value=362.23 id="pensja">
            </p>
            <p>
                <label for="godzinypracy">godziny pracy</label>
                <input type="text" name="godzinypracy" value="12/12" id="godzinypracy">
            </p>
            <p>
                <label for="posada">posada</label>
                <input type="text" name="posada" value="kasjer" id="posada">
            </p> -->
			<input type="submit"value="submit" name="submit">
		</form>
	</center>
</body>
</html>
