package ClioTemplates;

use vars qw(@ISA @EXPORT @EXPORT_OK %EXPORT_TAGS $VERSION);

use Exporter;

$VERSION = 1.00;
@ISA = qw(Exporter);

@EXPORT = qw(
          load_csv_template
	);

sub load_csv_template
{
    my ($file, $DEBUG) = @_;
    my @templates;

    open(file, $file);
    @template = <file>;
    close(file);

    return @template;
}
