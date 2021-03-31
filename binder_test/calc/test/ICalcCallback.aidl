package test;

/*
    Need change following lines in ICalcCallback.cpp

    in_callback = android::interface_cast<::test::ICalcCallback>(
        _aidl_data.readStrongBinder());

    //_aidl_ret_status = _aidl_data.readStrongBinder(&in_callback);
*/

interface ICalcCallback{    
    void done(int result);
}