<html>
    <head>
        <meta charset='utf-8'>
        <meta http-equiv='X-UA-Compatible' content='IE=edge'>
        <title>Fusuan Motors</title>
        <meta name='viewport' content='width=device-width, initial-scale=1'>
        <link rel='stylesheet' type='text/css' media='screen' href='./css/estoque.css'>
        <link rel='stylesheet' type='text/css' media='screen' href='./css/card_veiculo.css'>
        <link rel='stylesheet' type='text/css' media='screen' href='./css/detalhes.css'>
        <script type="text/javascript" src="./js/detalhes.js"></script>
        <script type="text/javascript" src="./js/modal.js"></script>
        <script type="text/javascript" src="./js/menu.js"></script>
        <script type="text/javascript" src="./js/search.js"></script>
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    </head>
    <body>
<?php

require_once 'controller/controller_estoque.inc';
require_once './estrutura/query.inc';
require_once './persistencia/persistencia.inc';
require_once './persistencia/persistencia_veiculo.inc';

require_once './estrutura/componentes/card_veiculo.inc';
require_once './estrutura/componentes/veiculo_miniatura.inc';
require_once './estrutura/componentes/menu.inc';
require_once './estrutura/query.inc';
require_once './view/view_detalhes.inc';
require_once './view/view_estoque.inc';
require_once './model/veiculo.inc';
require_once './model/modelo.inc';
require_once './model/marca.inc';
require_once './model/imagem_carro.inc';

new \Estrutura\Componentes\Menu();

new ControllerEstoque();
?>
</body>
</html>
        