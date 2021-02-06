<?php

require_once '../estrutura/funcoes.inc';
require_once '../estrutura/base.inc';
require_once '../estrutura/card_veiculo.inc';
require_once '../estrutura/veiculo_miniatura.inc';
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
        <link rel='stylesheet' type='text/css' media='screen' href='../css/detalhes.css'>
    </head>
    <body>
        <?php
        new \Estrutura\Menu();
        ?>
        <div class="main">
            <section class="vehicle-area-images">
                <div class="vehicle-image">
                    <img src="../images/monki-flip.jpg">
                </div>
                <?php
                    new Estrutura\VeiculoMiniatura();
                    new Estrutura\VeiculoMiniatura();
                    new Estrutura\VeiculoMiniatura();
                    new Estrutura\VeiculoMiniatura();
                    new Estrutura\VeiculoMiniatura();
                ?>
            </section>
            <section class="vehicle-info-area">
                <h2>Informações do Veículo</h2>
            </section>
        </div>
    </body>
</html>