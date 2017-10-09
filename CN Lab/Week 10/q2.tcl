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
 
set tcp [new Agent/TCP]
$tcp set class_ 1
$ns attach-agent $n0 $tcp
 
 
set sink [new Agent/TCPSink]
$ns attach-agent $n1 $sink
$ns connect $tcp $sink
$tcp set fid_ 2
 
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP
 
$ns at 0.1 "$ftp start"
$ns at 4.0 "$ftp stop"
$ns at 4.5 "finish"
 
$ns run
