
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
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



    if(!$conn)
        die(print_r(sqlsrv_errors(),true));
        $tablename = 'pracownik';
        $sql=("SELECT COLUMN_NAME
        FROM INFORMATION_SCHEMA.COLUMNS
        WHERE TABLE_NAME = '$tablename'");
        $stmt= sqlsrv_query($conn, $sql);
        if($stmt===false){
            die(print_r(sqlsrv_errors(), true));
        }
        $columns = [];
        while($row = sqlsrv_fetch_array($stmt, SQLSRV_FETCH_ASSOC)){
            $columns[]=$row['COLUMN_NAME'];
        }

        if(isset($_POST['submit'])){
            $questionmarks=[];
            $values = [];
            if($columns[0]=='id'){
            array_shift($columns);
            }
            foreach($columns as $colname){
                if($colname != 'id'){
                    $value = $_POST[$colname];
                    $questionmarks[]="?";
                    $values[]=$value;
                }
                // $sql="INSERT INTO $tablename ($column) VALUES($_REQUEST($column)";
                // echo "$sql";
                // sqlsrv_query($conn, $sql);
            }; 
        $sqlInsert = "INSERT INTO $tablename (" . implode(', ', $columns) . ") VALUES ( ".  implode(',',$questionmarks). ")";
        echo "$tablename (" . implode(', ', $columns) . ") VALUES ( ".  implode(',',$questionmarks). ")";
        $stmt2=sqlsrv_query($conn, $sqlInsert, $values);
        if ($stmt2 === false) {
            die(print_r(sqlsrv_errors(), true));
        }
        }



        // $pesel = $_REQUEST['pesel'];
        // $imie  = $_REQUEST['imie'];
        // $nazwisko = $_REQUEST['nazwisko'];
        // $nrtelefonu = $_REQUEST['nrtelefonu'];
        // $email = $_REQUEST['email'];
        // $pensja = $_REQUEST['pensja'];
        // $godzinypracy = $_REQUEST['godzinypracy'];
        // $posada = $_REQUEST['posada'];

        // $sql = "INSERT INTO pracownik (PESEL, imie, nazwisko, nr_telefonu, mail, pensja, godziny_pracy, posada)
        //         VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
        // $params = array($pesel, $imie, $nazwisko, $nrtelefonu, $email, $pensja, $godzinypracy, $posada);

        

        // $stmt = sqlsrv_query($conn, $sql, $params);

        // if ($stmt === false) {
        //     die(print_r(sqlsrv_errors(), true));
        // }
    
        // header('Location: http://localhost/testingattentionplease/app.php');
        header('Location: http://localhost/testingattentionplease/app.php');
        sqlsrv_close($conn);


    ?>
</body>

</html>