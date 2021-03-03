<?php

$today = time();
$wday = date('w', $today);   
echo date('d/m/Y', $today - ($wday - 1)*86400) . '<br>';
echo date('d/m/Y', $today - ($wday - 2)*86400) . '<br>';
echo date('d/m/Y', $today - ($wday - 3)*86400) . '<br>';
echo date('d/m/Y', $today - ($wday - 4)*86400) . '<br>';
echo date('d/m/Y', $today - ($wday - 5)*86400) . '<br>';
