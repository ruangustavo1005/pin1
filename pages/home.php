<?php

require_once '../estrutura/funcoes.inc';
require_once '../estrutura/base.inc';
require_once '../estrutura/card_veiculo.inc';
require_once '../estrutura/menu.inc';
require_once '../model/veiculo.inc';

?>
<!DOCTYPE html>
<html>
    <head>
        <meta charset='utf-8'>
        <meta http-equiv='X-UA-Compatible' content='IE=edge'>
        <title>Fusuan Motors</title>
        <meta name='viewport' content='width=device-width, initial-scale=1'>
        <link rel='stylesheet' type='text/css' media='screen' href='../css/home.css'>
        <script src='main.js'></script>
    </head>
    <body>
        <?php
        new \Estrutura\Menu();
        echo '<section class="area-veiculos">';
        for ($int = 0; $int < 3; $int++) {
            new \Estrutura\CardVeiculo(new Veiculo('Hyundai', 'HB20', 2030));
        }
        echo '</section>';
        ?>
    </body>
</html>