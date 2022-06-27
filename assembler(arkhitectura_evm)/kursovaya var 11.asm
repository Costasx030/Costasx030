
    ;DOSSEG
    .MODEL medium
    .386
    .STACK 100h
    .DATA
      Header DB    '| No | First name, Surname | Credit book | Mark   |   Date   |', '$'
      Timokhin DB  '| 2  | Timokhin K V        | 15502       |        |          |', '$'
      Smagin DB    '| 1  | Smagin P S          | 15503       |        |          |', '$'
      Verbov DB    '| 3  | Verbov P M          | 15505       |        |          |', '$'
      Semenov DB   '| 4  | Semenov V V         | 15507       |        |          |', '$'
      
      failed DB 'FAILED |', '$'
      passed DB 'PASSED |', '$'
      question DB ' Passed  exam? y or n', '$'
      qfinish DB 'Continue? ESC to exit', '$'

      y db 4
      dt_ db  ?,?,'-',?,?,'-',?,?,?,?,0Ah, 0Dh, '$'
  
.CODE
    
    
    printdate   MACRO dt_   ;??????? ?? ????? ??????? ????
        xor ax, ax
        mov ah, 04h
        int 1Ah
        mov al, dl
        aam 10h                     
        xchg    al,ah                   
        or  ax,'00'         
        stosw                           
        inc di 
        mov word ptr dt_, ax
        xor ah, ah
        mov al, dh
        aam 10h                     
        xchg    al,ah                  
        or  ax,'00'         
        stosw                           
        inc di 
        mov word ptr dt_+3, ax
        xor ah, ah
        mov al,ch
        aam 10h                     
        xchg    al,ah                   
        or  ax,'00'           
        stosw                           
        inc di 
        mov word ptr dt_+6, ax
        xor ah, ah
        mov al, cl
        aam 10h                     
        xchg    al,ah                   
        or  ax,'00'         
        stosw                           
        inc di 
        mov word ptr dt_+8, ax  
        mov dx, offset dt_
        mov ah,09h
        int 21h
    ENDM  
    
    writeChar MACRO chr ;???????? ?????? chr ?? ??????
        mov dl, chr
        mov ah, 02h
        int 21h
    ENDM
        
    newline MACRO ; ??????? ?? ????? ??????
        writeChar 10 
        writeChar 13 
    ENDM
    
    hline MACRO ; ??????? ?? ????? ?????????????? ?????
       LOCAL loop1
         newline
         mov cx, 60
       loop1: 
         mov dl, 45
         mov ah, 02h
         int 21h
       loop loop1
         newline
    ENDM 
 
    write MACRO msg ;???????? ?????? msg ?? ??????
        mov dx, offset msg
        mov ah, 09h
        int 21h
    ENDM

    
    terminate MACRO  ; ?????????? ?????????? ?????????
        mov ah,4ch
        int 21h
    ENDM
    
    movedown MACRO   ; ??????? ??????? ? ?????? ????? ??????
        mov DH, 20
        mov DL, 0
        mov ah, 2h
        int 10h
    ENDM
 
    moveto MACRO Y, X ; ??????? ??????? ?? ???????????
        mov DH, Y
        mov DL, X
        mov ah, 2h
        int 10h
    ENDM
  
    termination MACRO qfinish ; ?????? ? ?????????? ?????????
        movedown 
        write qfinish 
        mov ah, 10h
        int 16h
        cmp al, 27
    ENDM
 
    
start: 
        hline
        mov ax, @data
        mov es, ax
        mov ds, ax
        write Header
        hline
        write Smagin
        hline
        write Timokhin
        hline    
        write Verbov
        hline
        write Semenov
        
        termination qfinish
     check:
        jz t
        movedown
        write question
        mov ah, 10h
        int 16h
        cmp al, 121
        jz pass
        jnz fail
     pass:
         moveto Y, 43
         write passed
         printdate dt_
        xor dx, dx
        jz m1
     fail:
         moveto Y, 43
         write failed
         movedown
     m1:
         add Y, 2
         termination qfinish
         jnz check
     t:
         terminate
         movedown

END start
