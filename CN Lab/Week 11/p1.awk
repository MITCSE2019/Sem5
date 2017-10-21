BEGIN {
	
	fsDrop_udp = 0;
	numFs_udp = 0;
	fsDrop_tcp = 0;
	numFs_tcp = 0;
}
{
	action = $1;
	time = $2;
	from = $3;
	to = $4;
	type = $5;
	pktsize = $6;
	flow_id = $8;
	src = $9;
	dst = $10;
	seq_no = $11;
	packet_id = $12;
	
	if(from==0 && to==1 && action=="+")
        numFs_udp++;
    if(flow_id==2 && action=="d")
        fsDrops_udp++;
    if(from==0 && to==2 && action=="+")
        numFs_tcp++;
    if(flow_id==1 && action=="d")
        fsDrops_tcp++;
}
END{
	printf("UDP\t")
	printf("Number of packets sent: %d lost: %d\n",numFs_udp,fsDrops_udp);
	printf("Packet delivery ratio: %f\n",((numFs_udp-fsDrops_udp)/numFs_udp));
	printf("TCP\t")
	printf("Number of packets sent: %d lost: %d\n",numFs_tcp,fsDrops_tcp);
	printf("Packet delivery ratio: %f",((numFs_tcp-fsDrops_tcp)/numFs_tcp));
}