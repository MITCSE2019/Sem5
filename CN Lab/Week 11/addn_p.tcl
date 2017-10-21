set ns [new Simulator]

$ns color 1 red
$ns color 2 green

set nt [open simulate.nam w]
$ns namtrace-all $nt

set tr [open simulate.tr w]
$ns trace-all $tr

proc finish {} {
	global ns nt tr
	$ns flush-trace
	close $nt
	close $tr
	exec nam simulate.nam &
	exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 1.7Mb 20ms DropTail

$ns queue-limit $n0 $n2 5


$ns duplex-link-op $n2 $n3 orient right
$ns duplex-link-op $n2 $n0 orient left-up
$ns duplex-link-op $n2 $n1 orient left-down



$ns duplex-link-op $n0 $n2 queuePos 0.5

set udp [new Agent/UDP]
$ns attach-agent $n1 $udp

set null [new Agent/Null]
$ns attach-agent $n3 $null
$ns connect $udp $null
$udp set fid_ 1

set tcp [new Agent/TCP]
$tcp set class_ 1
$ns attach-agent $n0 $tcp


set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink
$ns connect $tcp $sink
$tcp set fid_ 2

set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP



set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size_ 1000
$cbr set rate_ 1mb
$cbr set random_ false

$ns at 0.1 "$cbr start"
$ns at 4.5 "$cbr stop"
$ns at 1.0 "$ftp start"
$ns at 4.0 "$ftp stop"
$ns at 5.0 "finish"

$ns run