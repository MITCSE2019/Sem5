set ns [new Simulator]
$ns color 1 green
$ns color 2 Red
$ns color 3 yellow
 
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
 
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
 
$ns duplex-link $n1 $n2 2Mb 20ms DropTail
$ns duplex-link $n3 $n4 1Mb 10ms DropTail
$ns duplex-link $n1 $n4 3Mb 10ms DropTail
 
$ns queue-limit $n1 $n2 10
$ns queue-limit $n3 $n4 10
$ns duplex-link-op $n1 $n2 orient down
$ns duplex-link-op $n3 $n4 orient up
$ns duplex-link-op $n1 $n4 orient right
 
 
set tcp [new Agent/TCP]
$tcp set class_ 1
$ns attach-agent $n1 $tcp
 
set sink [new Agent/TCPSink]
$ns attach-agent $n2 $sink
$ns connect $tcp $sink
$tcp set fid_ 2
 
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP
 
set udp [new Agent/UDP]
$ns attach-agent $n3 $udp
 
set null [new Agent/Null]
$ns attach-agent $n4 $null
$ns connect $udp $null
$udp set fid_ 1
 
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size_ 1000
$cbr set rate_ 1mb
$cbr set random_ false
 
set tcp1 [new Agent/TCP]
$tcp1 set class_ 2
$ns attach-agent $n1 $tcp1
 
set sink1 [new Agent/TCPSink]
$ns attach-agent $n4 $sink1
$ns connect $tcp1 $sink1
$tcp1 set fid_ 3
 
set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
$ftp1 set type_ FTP
 
 
$ns at 0.1 "$ftp start"
$ns at 4.0 "$ftp stop"
$ns at 0.2 "$ftp1 start"
$ns at 4.0 "$ftp1 stop"
$ns at 0.1 "$cbr start"
$ns at 4.0 "$cbr stop"
$ns at 4.5 "finish"
 
$ns run
