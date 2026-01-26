<html>
<body>
<p>
<?php
if (!isset($_GET['depart']) || !isset($_GET['arrivee'])) {
    die('manque les villes');
}

$ville1 = $_GET['depart'];
$ville2 = $_GET['arrivee'];

$distance = array(
    "paris" => array("nice" => 900, "lille" => 300),
    "nice" => array("paris" => 900, "tours" => 800, "lille" => 1200),
    "tours" => array("nice" => 800, "lille" => 500),
    "lille" => array("paris" => 300, "nice" => 1200, "tours" => 500)
);

if (isset($distance[$ville1][$ville2])) {
    $d = $distance[$ville1][$ville2];
    echo "La distance entre $ville1 et $ville2 est de $d km.";
} else {
    echo "Aucune distance connue entre $ville1 et $ville2.";
}
?>
</p>
</body>
</html>
