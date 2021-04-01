package test;


import test.ICalcCallback;
import test.Rectangle;
import test.CalcCommand;
import test.CalcResult;

interface ICalcService{
    const int CONST_A = 1;
    const int CONST_B = 2;
    const int CONST_C = 3;
    Rectangle getRect();
    int add(int a, int b, int c);
    void basicTypes(int anInt, long aLong, boolean aBoolean, float aFloat,
            double aDouble, String aString);            
    oneway void addAsync(int a, int b, int c, ICalcCallback callback);
    void InvokeCommand(in CalcCommand command, out CalcResult result);    
}