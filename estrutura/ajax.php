<?php

require_once './componentes/card_veiculo.inc';
require_once '../controller/controller_detalhes.inc';
require_once '../controller/controller_menu.inc';
require_once '../controller/controller_estoque.inc';
require_once '../controller/controller_agendamento.inc';
require_once '../view/view_detalhes.inc';
require_once '../view/view_estoque.inc';
require_once '../model/veiculo.inc';
require_once '../model/modelo.inc';
require_once '../model/marca.inc';


$oController = new $_POST['controller']();
$sMetodo = $_POST['processo'];
echo $oController->{$sMetodo}();

?>