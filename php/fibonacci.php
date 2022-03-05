<!--
Run time environment : PHP 7.4+
-->
<?php
    $x = array(0=>0,1=>1);
    $N = 1476; //the maximum that can be showed by PHP
    for($t=2;$t<=$N;++$t)
        {
           $x[]=$x[($t-1)]+$x[($t-2)];
        };    //make the fibonacci array
        
    function show_all_number_in_fibonacci_array() {
    global $x;
        var_dump($GLOBALS['x']);
    };    //show the fibonacci array

    function show_one_number_in_fibonacci_array($q) {
        global $x;
        var_dump($x[$q]); 
    }
?>
