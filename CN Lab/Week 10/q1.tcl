set ns [new Simulator]
$ns color 1 green
$ns color 2 Red
 
set nt [open simulate.nam w]
$ns namtrace-all $nt
 
set tr [open simulate.tr w]
$ns trace-all $tr
 
proc finish {} {
    global ns nt tr
    $ns flush-trace
    #Close the NAM trace file
    close $nt
    close $tr
    exec nam simulate.nam &
    exit 0
}
 
set n0 [$ns node]
set n1 [$ns node]
 
$ns duplex-link $n0 $n1 10Mb 10ms DropTail
$ns queue-limit $n0 $n1 10
$ns duplex-link-op $n0 $n1 orient right-down
 
$ns duplex-link-op $n0 $n1 queuePos 0.5
 
set udp [new Agent/UDP]
$ns attach-agent $n0 $udp
 
set null [new Agent/Null]
$ns attach-agent $n1 $null
$ns connect $udp $null
$udp set fid_ 1
 
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size_ 1000
$cbr set rate_ 1mb
$cbr set random_ false
 
$ns at 0.1 "$cbr start"
$ns at 4.0 "$cbr stop"
$ns at 4.5 "finish"
 
$ns run
