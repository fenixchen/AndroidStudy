#!/bin/sh

keytool -genkeypair -validity 365 -keystore mykey.keystore -keyalg RSA -keysize 2048
