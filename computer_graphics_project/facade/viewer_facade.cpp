#include "viewer_facade.h"

namespace facade {

ViewerFacade::ViewerFacade(): _intermediary(new Intermediary) {}

void ViewerFacade::execCommand(commands::BaseCommand *command) {
    if (command) {
        command->execute(_intermediary);
    }
}

}
