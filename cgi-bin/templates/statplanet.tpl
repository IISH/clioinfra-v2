<script type="text/javascript" src="/map/swfobject.js"></script>
<script type="text/javascript">	
function getURLParam(strParamName){
				var strReturn = "";
				var strHref = window.location.href;
				if ( strHref.indexOf("?") > -1 ){
					var strQueryString = strHref.substr(strHref.indexOf("?"));
					var aQueryString = strQueryString.split("&");
					for ( var iParam = 0; iParam < aQueryString.length; iParam++ ){
						if ( aQueryString[iParam].indexOf(strParamName.toLowerCase() + "=") > -1 ){
							var aParam = aQueryString[iParam].split("=");
							strReturn = aParam[1];
							break;
						}
					}				
				}
				return unescape(strReturn);
			}
			<!-- Adobe recommends that developers use SWFObject2 for Flash Player detection. -->
			<!-- For more information see the SWFObject page at Google code (http://code.google.com/p/swfobject/). -->
			<!-- Information is also available on the Adobe Developer Connection Under "Detecting Flash Player versions and embedding SWF files with SWFObject 2" -->
			<!-- Set to minimum required Flash Player version or 0 for no version detection -->
			var swfVersionStr = "9.0.45";
			<!-- xiSwfUrlStr can be used to define an express installer SWF. -->
			var xiSwfUrlStr = "";
			var flashvars = {};
			flashvars.location = getURLParam("l");
			flashvars.data = "%%datasetfile%%";
			flashvars.settings = "/map/settings.csv";
			var params = {};
			params.quality = "high";
			params.bgcolor = "#ffffff";
			params.play = "true";
			params.loop = "true";
			params.wmode = "window";
			params.allowfullScreen ="true";						
			params.scale = "showall";
			params.menu = "true";
			params.devicefont = "false";
			params.salign = "";
			params.allowscriptaccess = "sameDomain";
			var attributes = {};
			attributes.id = "StatPlanet";
			attributes.name = "StatPlanet";
			attributes.align = "middle";
			swfobject.createCSS("html", "height:100%; background-color: #ffffff;");
			swfobject.createCSS("body", "margin:0; padding:0; height:100%;");
			swfobject.embedSWF(
				"/map/StatPlanet.swf", "flashContent",
				"100%", "100%",
				swfVersionStr, xiSwfUrlStr,
				flashvars, params, attributes);		
		</script>	
<style type="text/css">
html { height:100%; }
body { height:100%; margin: 0;  }
</style>
<!-- start code only template -->
		<!-- SWFObject's dynamic embed method replaces this alternative HTML content for Flash content when enough JavaScript and Flash plug-in support is available. -->
       <div style="height:640px; width:940px; position:relative;">
		<div id="flashContent">
			<a href="http://www.adobe.com/go/getflash">
				<img src="http://www.adobe.com/images/shared/download_buttons/get_flash_player.gif" alt="Get Adobe Flash player" />
			</a>
			<p>This page requires Flash Player version 9.0.45 or higher.</p>
		</div></div>

<!-- end code only template -->
