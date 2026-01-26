<html>
    <body>
    <?php
        if (!isset($_GET["depart"]))
            die("manque la ville");
        $ville1=$_GET["depart"];
        $distance=array("paris"=>array("nice"=>900,"lille"=>300),
        "nice"=>array("paris"=>900,"tours"=>800,"lille"=>1200),
        "tours"=>array("nice"=>800,"lille" =>500),
        "lille"=>array("paris"=>300,"nice"=>1200,"tours"=>800));
        if (isset($distance[$ville1])) {
        ?>
            <h2>ville de d&eacute;part : <?php echo $_GET["depart"] ?></h2>
            <table border="1">
            <tr><th>destination</th><th>distance</th></tr>
        <?php
                foreach  ($distance[$ville1] as $ville2 => $dist)
                    echo "<tr><th>$ville2</th><th> $dist</th></tr>";
            } else
        echo '<p>pas de liaison à partir de cette ville</p>';
    ?>
    </body>
</html>