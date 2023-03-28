https://bytedance.feishu.cn/docx/EvmrdEYQ9oSuxLxhcqtcXHSnnff

Operator Format
    //prepare
    inputindex   = buffer[0]
    outindex     = buffer[1]
    operateindex = buffer[2]
    currentpointer = 0;

    SET 0 23   -> buffer[operateindex + 0] = 23
    COP 1 0   -> buffer[operateindex + 1] = buffer[operateindex + 0]
    // easy calculate operator
    ADD 2 1 0  ->add     
    DEL 2 1 0    delete
    MUL 2 1 0    multiple
    DIV 2 1 0    divison
    MAX 2 1 0    max
    MIN 2 1 0    min
    AND 2 1 0
    OR  2 1 0
    NOT 2 1
    BIG 2 1 0
    SMA 2 1 0
    EQA 2 1 0
    //JUMP
    IF 2 28 29
    JUMP 28

Easy impl 
    ADD 2 1 0  ->add     
    /*
    buffer[operateindex + 2] = buffer[operateindex + 1] + buffer[operateindex + 0]
    ++currentpointer;
    */
    IF 2 28 29
    /*
    currentpointer = buffer[operateindex + 2] !=0 ? 28 : 29
    */
    JUMP 28
    /*
    currentpointer = 28
    */

Easy show
    Q:
    B2 = B1 % 10   //= B1 - B1 / 10 * 10

    A:
    SET 3 10
    DIV 4 1 3
    MUL 4 4 3
    DEL 4 1 4
    COP 2 4
    -----------------------------------------
    Q:        
    B2 = B1
    while (B2 < B1 + 3){
    B2 = B2 + 1
    }   

    A:
    COP 2 1      // B2 = B1
    SET 3 3      // B3 = 3 
    ADD 4 3 1    // B4 = B3 + B1
    SMA 5 2 4    // B5 = B2 < B4
    IF  5 18 21  // currentpointer = (B5 > 0 ?) 18 : 21
    SET 6 1      // B6 = 1
    ADD 2 2 6    // B2 = B1 + B6
    JUMP 14      //currentpointer = 14
    -----------------------------------------  