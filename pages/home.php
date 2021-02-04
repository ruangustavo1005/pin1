<?php

require_once '../estrutura/Funcoes.inc';
//require_once '../estrutura/Base.php';
//require_once '../estrutura/CardVeiculo.inc';
//require_once '../estrutura/Menu.inc';
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
        for ($int = 0; $int < 9; $int++) {
            new \Estrutura\CardVeiculo();
        }
        echo '
      </section>';
        ?>
    </body>
</html>