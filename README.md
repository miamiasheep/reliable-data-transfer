# cs536_lab2

Lab2 of CS536 in purdue university

# How to Compile 

You can simply use make and it will generate prog2_arq, prog2_gbn and prog2_sr.

# Some implemetation detail need to be mentioned

1. I use non NACK protocol for prog2_arq. 

2. For timerinterrupt interval, I use 100 time units for prog2_arq, 30 time units for prog2_gbn and 30 time units for prog2_sr.

3. I found that 30 time units version of gbn is a little different from textbook, because it will resend the packet before the sender send 8 packets.
   
   Therefore, I run a version that timerinterrupt interval is 90 time units. But in the 90 time units version, the log is really long to get 10th packet.
   
   As a result, I annotate the log use 30 time units version but I also include log_gbn_90.txt which is the log of the 90 time units version of gbn.  

 
# Format of pdf file

In the pdf file, I use red color to annotate the first packet that is successfully received.

I also list the history of the first three packets to show that how my protocol recover packet from corrupted or lost.

Besides, I use blue pen to highlight first few recoveries. 