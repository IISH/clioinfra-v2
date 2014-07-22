<script language="JavaScript">
function toggletopics(source) {
  checkboxes = document.getElementById('topic');

  for each(var checkbox in checkboxes)
    checkbox.checked = source.checked;
}

function toggleindicators(source) {
  checkboxes = document.getElementById('indicator');
  for each(var checkbox in checkboxes)
    checkbox.checked = source.checked;
}
</script>

<div class="datasets searchpage">
  <form action=/datasets/searchresults method="get">
    <table border=0>
      <tr>
        <td colspan=3>
          <div class="filterstring">
            %%filterstring%%
          </div>
        </td>
        <td>
          <input type=submit value="ok">
        </td>
      </tr>
      <tr>
        <td width=25% valign=top>
        <div align="left"><br>
	        <table class="col" width=100%>
	          <tr>
              <td class="coltitle">Country</td>
            </tr>
	          <tr>
              <td>
  	          %%countriesblock%%
	            </td>
            </tr>
	        </table>
        </div>
        </td>
	<td width=5%>&nbsp;</td>
	<td width=70% valign=top colspan=2>

	<div id="timeblock">	
	<table width=100% border=0 valign=top>
	<tr>
        <td width=100% valign=top>
          <div align="left"><br>
          <table class="col" width=100%>
            <tr>
              <td colspan=3 class="coltitle">time period</td></tr>
            <tr>
              <td width=30%>
		from <input type="text" id="from_date" name="fromdate" value="" size=4> to <input type="text" id="to_date" name="todate" value="" size=4>
    	        %%yearsblock%%
              </td>
	      <td width=5%>
                <input style="width:25px" value="+" type="button" onclick='JavaScript:xmlhttpPost(%%actionurl%%, "timeblock")'>
              </td>
              <td width=65%>
              </td>

            </tr>
          </table>
	<input type="hidden" id="date_selected" value="%%dateselected%%">
	  </div>
        </div>
        </td>
	</tr>

	<tr>
        <td width=25% valign=top>
        <div align="left"><br>
	<div id="topicblock">
          <table class="col" width=100%>
            <tr>
              <td class="coltitle">topic</td></tr>
	      <tr><td width=10 colspan=2><input type="checkbox" onClick="toggletopics(this)" /> <b>All topics</b></td></tr>
            <tr>
              <td>
    	        %%topicsblock%%
              </td>
            </tr>
          </table>
        </div>
	</div>
        </td>
	</tr>

	<tr>
        <td width=25% valign=top align=center>
        <div align="left"><br>
          <table class="col" width=100%>
            <tr>
              <td class="coltitle">indicator</td>
            </tr>
              <tr><td width=10 colspan=2><input type="checkbox" onClick="toggleindicators(this)" /> <b>All indicators</b></td></tr>
            <tr>
              <td>
    	        %%indicatorsblock%%
              </td>
            </tr>
          </table>
        </div>
        </td>
	</tr>
	
	</tr></table>
      </tr>
      <tr>
        <td colspan=3></td>
        <td>
          <input type=submit value="ok">
        </td>
      </tr>

    </table>
  </form>
</div>
