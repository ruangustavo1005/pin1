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
        <link rel='stylesheet' type='text/css' media='screen' href='../css/estoque.css'>
        <link rel='stylesheet' type='text/css' media='screen' href='../css/card_veiculo.css'>
        <script type="text/javascript" src="../js/modal.js"></script>
    </head>
    <body>
        <?php
        new \Estrutura\Menu();
        $aCarros = [
            new Veiculo(1, 'Hyundai', 'HB20', 2010),
            new Veiculo(2, 'Hyundai', 'HB20', 2020),
            new Veiculo(3, 'Hyundai', 'HB20', 2030)
        ];
        echo '<section class="area-veiculos">';
        foreach ($aCarros as $oVeiculo) {
            new \Estrutura\CardVeiculo($oVeiculo);
        }
        echo '</section>';
        ?>
    </body>
</html>