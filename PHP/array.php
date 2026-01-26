<html>
 <body>

 <h2>Distances entre villes</h2>

 <table border="1" cellpadding="5">

<?php
$distance = array(
    array("paris", "nice", 900),
    array("nice", "tours", 800),
    array("tours", "lille", 500),
    array("paris", "lille", 300),
    array("nice", "lille", 1200)
);

for ($i = 0; $i < count($distance); $i++) {
    echo "<tr>";
    echo "<td>{$distance[$i][0]}</td>";
    echo "<td>{$distance[$i][1]}</td>";
    echo "<td>{$distance[$i][2]}</td>";
    echo "</tr>";
}
?>

 </table>

 </body>
</html>
