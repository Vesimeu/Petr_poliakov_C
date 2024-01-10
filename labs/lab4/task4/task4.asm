.ORIG x3000

    LEA R0, PROMPT       
    PUTS                

    LEA R1, NUMBERS      
    LEA R4, CONSTATEXP   
    LD R2, COUNT        

READ
    GETC                 
    OUT                
    STR R0, R4, #0       
    ADD R4, R4, #1      
    LD R3, NEG48        
    ADD R0, R0, R3      
    STR R0, R1, #0      
    ADD R1, R1, #1      
    ADD R2, R2, #-1      
    BRp READ  

    LEA R1, NUMBERS      
    LD R2, COUNT        
    ADD R2, R2, #-1     

SORTLOOP
    LD R4, COUNT         
    ADD R4, R4, #-1
    LEA R3, NUMBERS      

INLOOP
    LDR R0, R3, #0       
    LDR R1, R3, #1       
    NOT R5, R1
    ADD R5, R5, #1
    ADD R5, R0, R5       
    BRn SWAP       
    STR R1, R3, #0      
    STR R0, R3, #1

SWAP
    ADD R3, R3, #1       
    ADD R4, R4, #-1      
    BRp INLOOP       

    ADD R2, R2, #-1      
    BRp SORTLOOP        
    LD R0, NEWLINE
    OUT

    LEA R1, ORIGINAL
    LD R2, COUNT

OUTCONSTATEXP
    LDR R0, R1, #0       
    OUT                  
    ADD R1, R1, #1       
    ADD R2, R2, #-1      
    BRp OUTCONSTATEXP 

    LD R0, NEWLINE
    OUT

    LEA R1, NUMBERS
    LD R2, COUNT

OUTNUMBERS
    LDR R0, R1, #0       
    LD R3, POS48        
    ADD R0, R0, R3       
    OUT                  
    ADD R1, R1, #1      
    ADD R2, R2, #-1      
    BRp OUTNUMBERS    

    HALT                

PROMPT .STRINGZ "Enter 10 numbers: "
NUMBERS .BLKW 10       
CONSTATEXP .BLKW 10       
COUNT .FILL #10       
NEG48 .FILL #-48      
POS48 .FILL #48       
NEWLINE .FILL x000A     
.END