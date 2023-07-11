<?php
if (function_exists('findpath')) return;

function findpath($f) {
	$b = "";
	for ($i = 0; $i < 10; ++$i) {
		if (file_exists($b.$f)) {
			if ($b == "")
				$b = "./";
			return $b;
		}
		if (file_exists($b."base.inc"))
			return "";
		$b = "../".$b;
	}
	if ($i == 10)
		$b = "";
	return $b;
}
$b = findpath("base.inc");
?>
