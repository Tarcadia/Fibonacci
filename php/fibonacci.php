<?php
    $x = array(0,1);
    for($t=2;$t<=9999;++$t)
        {
           $x[$t]=$x[$t-1]+$[$t-2]
        };    //make the fibonacci array

    function show_all_number_in_fibonacci_array() {
        var_dump($x)
    };    //show the fibonacci array
    
    function show_one_number_in_fibonacci_array($q) {
      var_dump($x[$q]);
    };
  show_all_number_in_fibonacci_array();
    
?>
