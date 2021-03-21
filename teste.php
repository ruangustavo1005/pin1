<?php

//$today = time();
//$wday = date('w', $today);   
//echo date('d/m/Y', $today - ($wday - 1)*86400) . '<br>';
//echo date('d/m/Y', $today - ($wday - 2)*86400) . '<br>';
//echo date('d/m/Y', $today - ($wday - 3)*86400) . '<br>';
//echo date('d/m/Y', $today - ($wday - 4)*86400) . '<br>';
//echo date('d/m/Y', $today - ($wday - 5)*86400) . '<br>';

set_time_limit(0);


$string = 'Lorem ipsum dolor sit amet';

/* Cliente */
//for($i = 1; $i <= 100000; $i++) {
//    file_put_contents('sqltest.txt', "insert into farmacia.cliente(id_cliente, cpf, nome, data_nascimento) values ({$i}, '". cpfRandom("0")."', '".str_shuffle($string). "', '". randomData()."');". PHP_EOL, FILE_APPEND);
//}

/* Colaborador */
//for($i = 1; $i <= 100000; $i++) {
//    file_put_contents('sqltest.txt', "insert into farmacia.colaborador(id_colaborador, nome, nro_dependentes, rg, sexo, descricao, data_contratacao, salario_bruto, id_gerente) values ({$i}, '".str_shuffle($string). "', '". random_int(0, 3)."', '". random_int(1000000, 9999999)."', '". randonSexo()."', '".str_shuffle($string). "', '". randomData()."', '". random_int(1200, 5000)."', 1);". PHP_EOL, FILE_APPEND);
//}

/* Fornecedor */
//for($i = 1; $i <= 100000; $i++) {
//    file_put_contents('sqltest.txt', "insert into farmacia.fornecedor(id_fornecedor, nome, descricao) values ({$i}, '".str_shuffle($string). "', '".str_shuffle($string). "');". PHP_EOL, FILE_APPEND);
//}

/* Remédio */
//for($i = 1; $i <= 100000; $i++) {
//    file_put_contents('sqltest.txt', "insert into farmacia.remedio(id_remedio, nome, valor, tipo, qtd_comprimidos, volume_liquido, descricao, id_fornecedor) values ({$i}, '".str_shuffle($string). "', '". random_int(3, 250)."', '". random_int(1, 2)."', '". random_int(4, 50)."', '". random_int(5, 1000)."', '".str_shuffle($string). "', {$i});". PHP_EOL, FILE_APPEND);
//}

/* Estoque */
//for($i = 1; $i <= 100000; $i++) {
//    file_put_contents('sqltest.txt', "insert into farmacia.estoque(id_remedio, id_estoque, data, valor, data_validade) values ({$i}, {$i}, '". randomData(1). "', '". random_int(3, 250)."', '". randomData(2). "');". PHP_EOL, FILE_APPEND);
//}

/* Venda */
//for($i = 1; $i <= 100000; $i++) {
//    file_put_contents('sqltest.txt', "insert into farmacia.venda(id_venda, data, pago, id_cliente, id_colaborador) values ({$i}, '". randomData(1). "', '". random_int(0, 1)."', {$i}, {$i});". PHP_EOL, FILE_APPEND);
//}

/* Venda Remédio */
//for($i = 1; $i <= 100000; $i++) {
//    file_put_contents('sqltest.txt', "insert into farmacia.venda_remedio(id_remedio, id_estoque, id_venda) values ({$i}, {$i}, {$i});". PHP_EOL, FILE_APPEND);
//}

/* Restrição Médica */
//for($i = 1; $i <= 100000; $i++) {
//    file_put_contents('sqltest.txt', "insert into farmacia.restricao_medica(id_restricao_medica, descricao, criticidade) values ({$i}, '". str_shuffle($string)."', '". random_int(0, 5)."');". PHP_EOL, FILE_APPEND);
//}

/* Remédio Restrição */
//for($i = 1; $i <= 100000; $i++) {
//    file_put_contents('sqltest.txt', "insert into farmacia.remedio_restricao(id_restricao_medica, id_remedio) values ({$i}, {$i});". PHP_EOL, FILE_APPEND);
//}

/* Configurações */
for($i = 1; $i <= 100000; $i++) {
    file_put_contents('sqltest.txt', "insert into farmacia.configuracoes(tipo, id_configuracao, configuracao) values ('". random_int(1, 3)."', {$i}, '{teste: ". str_shuffle($string).", exemplo: ".str_shuffle($string). ", config: ".str_shuffle($string)."}');". PHP_EOL, FILE_APPEND);
}


function randomData($i = 1) {
    if($i == 1) {
        return ''. random_int(10, 25).'/' . random_int(10, 12).'/'. random_int(1990, 2021);
    } else {
        return ''. random_int(10, 25).'/' . random_int(10, 12).'/'. random_int(2022, 2030);
    }
}

function cpfRandom($mascara = "1") {
    $n1 = rand(0, 9);
    $n2 = rand(0, 9);
    $n3 = rand(0, 9);
    $n4 = rand(0, 9);
    $n5 = rand(0, 9);
    $n6 = rand(0, 9);
    $n7 = rand(0, 9);
    $n8 = rand(0, 9);
    $n9 = rand(0, 9);
    $d1 = $n9 * 2 + $n8 * 3 + $n7 * 4 + $n6 * 5 + $n5 * 6 + $n4 * 7 + $n3 * 8 + $n2 * 9 + $n1 * 10;
    $d1 = 11 - (mod($d1, 11) );
    if ($d1 >= 10) {
        $d1 = 0;
    }
    $d2 = $d1 * 2 + $n9 * 3 + $n8 * 4 + $n7 * 5 + $n6 * 6 + $n5 * 7 + $n4 * 8 + $n3 * 9 + $n2 * 10 + $n1 * 11;
    $d2 = 11 - (mod($d2, 11) );
    if ($d2 >= 10) {
        $d2 = 0;
    }
    $retorno = '';
    if ($mascara == 1) {
        $retorno = '' . $n1 . $n2 . $n3 . "." . $n4 . $n5 . $n6 . "." . $n7 . $n8 . $n9 . "-" . $d1 . $d2;
    } else {
        $retorno = '' . $n1 . $n2 . $n3 . $n4 . $n5 . $n6 . $n7 . $n8 . $n9 . $d1 . $d2;
    }
    return $retorno;
}

function mod($dividendo, $divisor) {
    return round($dividendo - (floor($dividendo / $divisor) * $divisor));
}


function randonSexo() {
    return random_int(1, 2) == 1 ? 'M' : 'F';
}