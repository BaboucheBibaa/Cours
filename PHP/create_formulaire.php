<?php 
$nbtext = (int)$_POST['nbtext'];
$nbselect = (int)$_POST['nbselect'];
$optionselect = $_POST['optionselect'];

echo "<h2>Mon Formulaire</h2>";
echo "<form><fieldset>";
for ($i = 0; $i < $nbtext; $i++) {
    echo "<input type='input$i' name='propose'><br>";
}
echo "</fieldset><fieldset>";
$options =explode("\n",$optionselect);
foreach ($options as $ligne_options){
    $options=explode(";",$ligne_options);

    echo "<select name='$options[0]'>";

    foreach ( $options as $option ) {
        echo "  <option value='$option'>$option</option>";
    }
    echo "</select><br>";
}
echo "</fieldset></form>";

?>