<div id="timeblock">	
	<table width=100% border=0 valign=top>
	<tr>
        <td width=100% valign=top>
        <div align="left"><br>
          <table class="col" width=100% border=0>
            <tr>
              <td class="coltitle" colspan=3>time period</td></tr>
            <tr>
              	<td width=30%>
		from <input type="text" id="from_date" name="fromdate" value="%%fromdate%%" size=4> to <input type="text" id="to_date" name="todate" value="%%todate%%" size=4><br />
    	        %%yearsblock%%
              	</td>
	  	<td width=5%>
		<input style="width:25px" value="+" type="button" onclick='JavaScript:xmlhttpPost(%%actionurl%%, "timeblock")'>
		</td>
		<td width=65%>
		%%extrayears%%
		</td>
            </tr>
          </table>
<input type="hidden" id="date_selected" value="%%dateselected%%">
</div>
