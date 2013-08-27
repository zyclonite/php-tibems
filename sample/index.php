<?php
/* ***********************IMPORTANT ***************************************
 *  Copyright (C) 2006 Lukas Prettenthaler <http://zyclonite.net>         *
 *  This program is free software; you can redistribute it and/or modify  *
 *  it under the terms of the GNU General Public License as published by  *
 *  the Free Software Foundation; either version 2 of the License.        *
 *                                                                        *
 *                      ********************                              *
 *                                                                        *
 *  This program is distributed in the hope that it will be useful,       *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *  GNU Library General Public License for more details.                  *
 *                                                                        *
 *                      ********************                              *
 *                                                                        *
 * You are highly encouraged to send your changes to <rdx@wsn.at>         *
 * for possible incorporation into the main distribution.                 *
 * By sending these changes to <rdx@wsn.at>, it is assumed                *
 * that you are offering <rdx@wsn.at> the unlimited,                      *
 * non-exclusive right to reuse, modify, and relicense the code.          *
 **************************************************************************/

echo "<html><head><title>tibco jms php extension sample</title></head><body>\n";

if(($_POST['server'] != "") && ($_POST['user'] != "") && ($_POST['pass'] != "") && ($_POST['message'] != "") && ($_POST['dest'] != "") && ($_POST['op'] == "send")) {

	tibco_connect($_POST['server'], $_POST['user'], $_POST['pass']);
	if($_POST['queue'] == "queue") {
		tibco_sendmsg($_POST['dest'], $_POST['message'], false);
	}else{
		tibco_sendmsg($_POST['dest'], $_POST['message'], true);
	}
	tibco_disconnect();
	echo "<small>Message sent</small>\n";

}

if(($_POST['server'] != "") && ($_POST['user'] != "") && ($_POST['pass'] != "") && ($_POST['dest'] != "") && ($_POST['op'] == "recv")) {

	echo "<small>Message:<br><br>\n";
	tibco_connect($_POST['server'], $_POST['user'], $_POST['pass']);
	if($_POST['queue'] == "queue") {
		echo tibco_recvmsg($_POST['dest'], false, 1000);
	}else{
		echo tibco_recvmsg($_POST['dest'], true, 1000);
	}
	tibco_disconnect();
	echo "</small>\n";

}else{

echo "<br>Send Messsage:<br><form name=\"form\" action=\"\" method=\"post\"><input type=\"hidden\" name=\"op\" value=\"send\">\n";
echo "Server: <input type=\"text\" name=\"server\" value=\"".$_POST['server']."\"><br>\n";
echo "User: <input type=\"text\" name=\"user\" value=\"".$_POST['user']."\"><br>\n";
echo "Password: <input type=\"password\" name=\"pass\" value=\"".$_POST['pass']."\"><br>\n";
echo "Destination: <input type=\"text\" name=\"dest\" value=\"".$_POST['dest']."\"><br>\n";
echo "<input type=\"radio\" name=\"queue\" value=\"queue\" checked> Queue <input type=\"radio\" name=\"queue\" value=\"topic\"> Topic<br>\n";
echo "Message: <textarea name=\"message\" cols=\"50\" rows=\"25\"></textarea><br>\n";
echo "<input type=\"submit\" value=\"Abschicken\"></form>\n";

echo "<br><br>Receive Message:<br><form name=\"form\" action=\"\" method=\"post\"><input type=\"hidden\" name=\"op\" value=\"recv\">\n";
echo "Server: <input type=\"text\" name=\"server\" value=\"".$_POST['server']."\"><br>\n";
echo "User: <input type=\"text\" name=\"user\" value=\"".$_POST['user']."\"><br>\n";
echo "Password: <input type=\"password\" name=\"pass\" value=\"".$_POST['pass']."\"><br>\n";
echo "Destination: <input type=\"text\" name=\"dest\" value=\"".$_POST['dest']."\"><br>\n";
echo "<input type=\"radio\" name=\"queue\" value=\"queue\" checked> Queue <input type=\"radio\" name=\"queue\" value=\"topic\"> Topic<br>\n";
echo "<input type=\"submit\" value=\"Empfangen\"></form>\n";

}

echo "</body></html>\n";

?>
