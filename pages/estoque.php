<?php

require_once '../estrutura/componentes/card_veiculo.inc';
require_once '../estrutura/componentes/veiculo_miniatura.inc';
require_once '../estrutura/componentes/menu.inc';
require_once '../estrutura/query.inc';
require_once '../view/view_detalhes.inc';
require_once '../model/veiculo.inc';
require_once '../model/modelo.inc';
require_once '../model/marca.inc';

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
        <link rel='stylesheet' type='text/css' media='screen' href='../css/detalhes.css'>
        <script type="text/javascript" src="../js/detalhes.js"></script>
        <script type="text/javascript" src="../js/modal.js"></script>
    </head>
    <body>
        <?php
        new Query();
        
        
        $aCarros = [
            
        ];
        echo '<section class="area-veiculos">';
        foreach ($aCarros as $oVeiculo) {
            new Estrutura\Componentes\CardVeiculo($oVeiculo);
        }
        echo '</section>';
        ?>
    </body>
</html>