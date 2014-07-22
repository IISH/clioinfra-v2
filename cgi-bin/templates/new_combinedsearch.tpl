<script type="text/javascript">
<!--//--><![CDATA[// ><!--
jQuery(document).ready(function($){
$('ul.bef-tree').tristate();
});
//--><!]]>
</script>

<div class="datasets searchpage">
  <form action=/datasets/searchresults method="get">
    <table border=0 align=right>
      <tr>
        <td colspan=3>
        </td>
        <td>
          <input type=submit value="ok">
        </td>
      </tr>
    </table>

    <table class="col" width=49% border=0>
    <tr>
      <td class="coltitle">time period</td>
    </tr>
    <tr>
        <td>
         <div class="datasets-searchyear">from<br> <input type="text" id="from_date" name="fromdate" value="" size=4></div> <div class="datasets-searchyear">to<br> <input type="text" id="to_date" name="todate" value="" size=4></div>
        %%yearsblock%%
        </td>
    </tr>
    </table>

    <table width=100%>
     <tr>
      <td width=49% valign=top>
        <div align="left">
	        <table class="col" width=100%>
	          <tr>
              <td class="coltitle">Country</td>
            </tr>
	          <tr>
              <td>
                <div class="countriesblock">
      	          %%countriesblock%%
                </div>
	            </td>
            </tr>
	        </table>
        </div>
      </td>
      <td width="2%">
        &nbsp;
      </td>
      <td width=49% valign=top>
        <div align="left">
          <table class="col" width=100%>
            <tr>
              <td class="coltitle">topic</td>
            </tr>
            <tr>
              <td>
                <div class="topicsblock">
                  %%topicsblock%%
                </div>
              </td>
            </tr>
          </table>
        </div>
      </td>

    </tr>
    </table>

<table align=right>
      <tr>
        <td colspan=3></td>
        <td>
          <input type=submit value="ok">
        </td>
      </tr>

    </table>
  </form>
</div>
