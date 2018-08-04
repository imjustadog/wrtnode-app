#!/bin/sh
(
echo "From:<chaojishumi@163.com>";
echo "To:<chaojishumi@163.com>";
echo "Subject: test"
echo "";
echo "hello world"
echo ""
)|ssmtp -v -f "638" -F "smc638" chaojishumi@163.com

