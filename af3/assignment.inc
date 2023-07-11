<?

class AssignmentMedia extends MediaLibrary {
	var $assignnum;

	function AssignmentMedia($assignnum, $directory, $imageDir) {
		$this->assignnum = $assignnum;
		$this->MediaLibrary($directory, $imageDir);
	}

	function scanFilename($filename) {
		if (preg_match("/^".$this->assignnum."\.(rm|rpm|ram|mp4)/", $filename, $matches)) {
			// matches assignnum.rpm
			if (isset($this->contents[1])) {
				$media->addFilename($matches[0]);
			} else {
				$this->set(1, new Media($matches[0]));
			}
		}
	}
}

class Assignment extends LTObject {
	var $num;
	var $title;
	var $afterphoto;
	var $exhibits;
	var $reports;
	var $media;
	var $label;

	function Assignment($assignnum,$forinfo) {
		global $allAssignments;

		$b = findpath("base.inc");

		$this->LTObject();

		$this->num = $assignnum;
		$this->exhibits = array();
		$this->reports = array();
		$this->imagepath = $b.'images/'.$this->num.'/best/';
		$this->label = "Assignment #".$assignnum;

		$this->forinfo = $forinfo;

		if ($forinfo)
			return;

		$dh = @opendir($this->imagepath);
		if (!$dh) {
			$this->imagepath = $b.'images/'.$this->num.'/';
			$dh = @opendir($this->imagepath);
		}
		if ($dh) {
			while (($file = readdir($dh)) != false) {
				if (preg_match("/^(.*?)\.(gif|jpg|jpeg)/", $file, $matches)) {
					if ($matches[1] > 0) {
						$this->images[$matches[1]] = $matches[0];
					} else {
						$this->images[] = $matches[0];
					}
				}
			}
			closedir($dh);
		}// else
		//	echo "NO ASSIGNMENT IMAGE DIRECTORY: '".$this->imagepath."' FOR ASSIGNMENT ".$this->num;
		$this->media = new AssignmentMedia($this->num, ".", $b.'images/'.$this->num);
	}
	function label($label) {
		$this->label = $label;
	}
	function title($title) {
		$this->title = $title;
	}
	function afterphoto($line) {
		$this->afterphoto = "?>".$line;
	}
	function exhibit($exhibit) {
		$this->exhibits[] =& exhibitobject($exhibit);
	}
	function url() {
		global $b;
		return $b."reports/".$this->num."/".$this->num.".php";
	}
}
function assignemail($text = "YURI") {
	echo "<a href=\"mailto:yuri@myono.com\">$text</a>";
}
function questions() {
	global $exhibit;
	if ($exhibit->flags['questions']) return;
		$exhibit->flags['questions'] = 1;
	echo "<span class=\"bodytext2\">&nbsp;&nbsp;<br></span>";
}
function exhibition() {
	global $exhibit;
	questions();
	echo "<span class=\"bodytext2\">- - - E X H I B I T I O N !<br></span><span class=\"bodytext2\">&nbsp;&nbsp;<br></span><span class=\"bodytext2\">";

}
function exhibition_history() {
	global $exhibit;
	if ($exhibit->flags['exhibition_history']) return;
		$exhibit->flags['exhibition_history'] = 1;
	questions();
	echo "<span class=\"bodytext2\">- - - E X H I B I T I O N _ H I S T O R Y:<br></span><span class=\"bodytext2\">&nbsp;&nbsp;<br></span><span class=\"bodytext2\">";

}

function assignbegin() {
	global $b, $assign, $assignincluded, $reportincluded;
	include("assignbegin.inc");
	include("assignmiddle.inc");
}
function assignintro() {
	global $b, $assign, $assignincluded, $reportincluded;
	include("assignbegin.inc");
}
function assignmiddle() {
	global $b, $assign, $assignincluded, $reportincluded;
	include("assignmiddle.inc");
}
function assignend() {
	global $b, $assign, $assignincluded, $reportincluded;
	questions();
	include("assignend.inc");
}
function friendsbegin() {
	global $b, $assign, $assignincluded, $reportincluded;
	include("friendsbegin.inc");
	include("assignmiddle.inc");
}
function friendsintro() {
	global $b, $assign, $assignincluded, $reportincluded;
	include("friendsbegin.inc");
}
?>