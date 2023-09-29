<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="style1.css">
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


$tableName = 'pracownik';

$sql = "SELECT COLUMN_NAME
        FROM INFORMATION_SCHEMA.COLUMNS
        WHERE TABLE_NAME = ?";

$params = [$tableName];

$stmt = sqlsrv_query($conn, $sql, $params);

if ($stmt === false) {
    die(print_r(sqlsrv_errors(), true));
}

$columns = [];

while ($row = sqlsrv_fetch_array($stmt, SQLSRV_FETCH_ASSOC)) {
    $columns[] = $row['COLUMN_NAME'];
}
sqlsrv_close($conn);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dynamic Table</title>
    <link rel="stylesheet" href="style1.css">
</head>
<body>
    <div>
        <button class="addRecord"><a href="./app1.php">Dodaj rekordy</a></button>
    </div>
    <table>
        <tr>
            <?php
            foreach ($columns as $colname) {
                echo "<th>$colname</th>";
            }
            ?>
        </tr>
        <?php
        $conn = sqlsrv_connect($serverName, $connection);
        $sql = "SELECT * FROM $tableName";
        $stmt = sqlsrv_query($conn, $sql);
        
        while ($row = sqlsrv_fetch_array($stmt, SQLSRV_FETCH_ASSOC)) {
            echo "<tr>";
            foreach ($columns as $colname) {
                echo "<td>" . $row[$colname] . "</td>";
            }
            echo "<td><form method='post'><input type='hidden' name='delete_id' value='" . $row['id'] . "'>";
            echo "<button type='submit'>Delete</button></form></td>";
            echo "</tr>";
        }
        
        sqlsrv_close($conn);
        ?>
    </table>
    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["delete_id"])) {
        $deleteId = $_POST["delete_id"];
        $conn = sqlsrv_connect($serverName, $connection);
        $sqlDelete = "DELETE FROM '$tableName' WHERE id = ?";
        $params = [$deleteId];
        $stmtDelete = sqlsrv_query($conn, $sqlDelete, $params);

        if ($stmtDelete === false) {
            die(print_r(sqlsrv_errors(), true));
        }
        
        sqlsrv_close($conn);
        header("Location: " . $_SERVER['PHP_SELF']);
        exit();
    }
    ?>
</body>
</html>

