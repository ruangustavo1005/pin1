<?php

require_once '../controller/controller_detalhes.inc';
require_once '../view/view_detalhes.inc';
require_once '../model/veiculo.inc';
require_once '../model/modelo.inc';
require_once '../model/marca.inc';


$oController = new $_POST['controller']();
$sMetodo = $_POST['processo'];
echo $oController->{$sMetodo}();

?>